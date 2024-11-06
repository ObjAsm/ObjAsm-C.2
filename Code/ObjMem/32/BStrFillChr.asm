; ==================================================================================================
; Title:      BStrFillChr.asm
; Author:     G. Friedrich
; Version:    C.1.2
; Notes:      Version C.1.2, December 2020
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

TARGET_STR_TYPE = STR_TYPE_WIDE
TARGET_STR_AFFIX textequ <W>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrFillChr
; Purpose:    Fill a preallocated BSTR with a character.
; Arguments:  Arg1: -> String.
;             Arg2: Character.
;             Arg3: Character Count.
; Return:     Nothing.

% include &ObjMemPath&Common\BStrFillChr_TX.inc

end
