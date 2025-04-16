; ==================================================================================================
; Title:      AreVisualStylesEnabled.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

% include &IncPath&Windows\uxtheme.inc

; --------------------------------------------------------------------------------------------------
; Procedure:  AreVisualStylesEnabled
; Purpose:    Determine if there is an activated theme for the running application
; Arguments:  None.
; Return:     eax = TRUE if the application is themed, otherwise FALSE.

OPTION PROC:NONE

.code
align ALIGN_CODE
AreVisualStylesEnabled proc
  .if $invoke(IsThemeActive) != 0
    invoke IsAppThemed
  .endif
  ret
AreVisualStylesEnabled endp

OPTION PROC:DEFAULT

end
