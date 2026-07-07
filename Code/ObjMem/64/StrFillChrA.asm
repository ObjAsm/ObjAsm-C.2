; ==================================================================================================
; Title:      StrFillChrA.asm
; Author:     G. Friedrich
; Version:    C.1.2
; Notes:      Version C.1.2, December 2020
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <StrFillChrA>

; --------------------------------------------------------------------------------------------------
; Procedure:  StrFillChrA
; Purpose:    Fill a preallocated String with a character.
; Arguments:  Arg1: -> StringA.
;             Arg2: Character count.
;             Arg3: ANSI character.
; Return:     Nothing.
; Note:       The procedure sets after dCount chars a ZTC.

% include &ObjMemPath&Common\StrFillChr_TXP.inc

end
