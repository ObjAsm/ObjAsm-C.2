; ==================================================================================================
; Title:      GUID2StrW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GUID2StrW
; Purpose:    Convert a GUID to a WIDE string.
; Arguments:  Arg1: -> Destination WIDE string Buffer.
;                   It must hold at least 36 characters plus a ZTC (= 74 BYTEs).
;             Arg2: -> GUID.
; Return:     Nothing.

% include &ObjMemPath&Common\GUID2Str_WXP.inc

end
