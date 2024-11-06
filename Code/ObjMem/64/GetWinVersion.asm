; ==================================================================================================
; Title:      GetWinVersion.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, August 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetWinVersion
; Purpose:    Get Windows true version numbers directly from NTDLL.
; Arguments:  Arg1: -> Major Version. Can be NULL.
;             Arg2: -> Minor Version. Can be NULL.
;             Arg3: -> Build Number. Can be NULL.
; Return:     Nothing.
; Links:      https://www.geoffchappell.com/studies/windows/win32/ntdll/api/ldrinit/getntversionnumbers.htm

% include &ObjMemPath&Common\GetWinVersion_X.inc

end
