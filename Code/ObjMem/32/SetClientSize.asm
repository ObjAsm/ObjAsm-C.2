; ==================================================================================================
; Title:      SetClientSize.asm
; Author:     MichelW / G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SetClientSize
; Purpose:    Set the client window size.
; Arguments:  Arg1: Target window handle.
;             Arg2: Client area width in pixel.
;             Arg3: Client area height in pixel.
; Return:     Nothing.

% include &ObjMemPath&Common\SetClientSize_X.inc

end
