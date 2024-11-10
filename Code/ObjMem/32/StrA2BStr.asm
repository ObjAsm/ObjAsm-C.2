; ==================================================================================================
; Title:      StrA2BStr.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrA2BStr
; Purpose:    Convert a ANSI string into a BStr.
; Arguments:  Arg1: -> Destination BStr buffer = Buffer address + sizeof(DWORD).
;             Arg2: -> Source ANSI string.
; Return:     eax = Number of BYTEs in the BSTR, including the ZTC.

% include &ObjMemPath&Common\StrA2BStr_X.inc

end
