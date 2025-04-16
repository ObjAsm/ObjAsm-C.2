; ==================================================================================================
; Title:      GUID2BStr.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  GUID2BStr
; Purpose:    Convert a GUID to a BStr.
; Arguments:  Arg1: -> Destination BStr Buffer. It must hold at least 36 WIDE characters plus a ZTC.
;             Arg2: -> GUID.
; Return:     Nothing.

% include &ObjMemPath&Common\GUID2BStr_XP.inc

end
