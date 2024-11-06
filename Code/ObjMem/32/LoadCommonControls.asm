; ==================================================================================================
; Title:      LoadCommonControls.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  LoadCommonControls
; Purpose:    Invoke InitCommonControls with a correctly filled input structure.
; Arguments:  Arg1: ICC_COOL_CLASSES, ICC_BAR_CLASSES, ICC_LISTVIEW_CLASSES, ICC_TAB_CLASSES,
;                   ICC_USEREX_CLASSES, etc.
; Return:     Nothing.

% include &ObjMemPath&Common\LoadCommonControls_X.inc

end
