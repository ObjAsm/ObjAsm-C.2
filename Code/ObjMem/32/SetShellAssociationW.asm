; ==================================================================================================
; Title:      SetShellAssociationW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <SetShellAssociationW>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SetShellAssociationW
; Purpose:    Set association for a file extension.
; Arguments:  Arg1: TRUE = system wide association, FALSE = user account only.
;             Arg2: -> File extension (without dot).
;             Arg3: -> Verb ("open", "print", "play", "edit", etc.). This verb is displayed
;                   in the explorer context menu of a file with this extension.
;             Arg4: -> Application to associate with (full path).
;             Arg5: -> Application arguments, usually $OfsCStr("%1").
; Return:     eax = HRESULT.
; Note:       dGlobal = TRUE requires adminitrative rights.

% include &ObjMemPath&Common\SetShellAssociation_TX.inc

end
