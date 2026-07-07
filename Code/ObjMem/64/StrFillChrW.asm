; ==================================================================================================
; Title:      StrFillChrW.asm
; Author:     G. Friedrich
; Version:    C.1.2
; Notes:      Version C.1.2, December 2020
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <StrFillChrW>

; --------------------------------------------------------------------------------------------------
; Procedure:  StrFillChrW
; Purpose:    Fill a preallocated String with a character.
; Arguments:  Arg1: -> StringW.
;             Arg2: Character count.
;             Arg3: WIDE character.
; Return:     Nothing.
; Note:       The procedure sets after dCount chars a ZTC.

% include &ObjMemPath&Common\StrFillChr_TXP.inc

end
