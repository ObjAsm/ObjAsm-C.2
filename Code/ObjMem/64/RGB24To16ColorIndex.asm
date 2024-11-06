; ==================================================================================================
; Title:      RGB24To16ColorIndex.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RGB24To16ColorIndex
; Purpose:    Map a 24 bit RGB color to a 16 color palette index.
; Arguments:  Arg1: RGB color.
; Return:     eax = Palette index.

% include &ObjMemPath&Common\RGB24To16ColorIndex_XP.inc

end
