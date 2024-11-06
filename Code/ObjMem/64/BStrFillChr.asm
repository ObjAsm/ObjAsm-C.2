; ==================================================================================================
; Title:      BStrFillChr.asm
; Author:     G. Friedrich
; Version:    C.1.2
; Notes:      Version C.1.2, December 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrFillChr
; Purpose:    Fill a preallocated BSTR with a character.
; Arguments:  Arg1: -> String.
;             Arg2: Character.
;             Arg3: Character Count.
; Return:     Nothing.

% include &ObjMemPath&Common\BStrFillChr_TX.inc

end
