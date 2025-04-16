; ==================================================================================================
; Title:      SetShellPerceivedTypeW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <SetShellPerceivedTypeW>

; --------------------------------------------------------------------------------------------------
; Procedure:  SetShellPerceivedTypeW
; Purpose:    Set shell perception of a file type.
; Arguments:  Arg1: TRUE = system wide perseption, FALSE = user account only.
;             Arg2: -> File extension (without dot).
;             Arg3: -> Type (Folder, Text, Image, Audio, Video, Compressed, Document, System, 
;                            Application, Gamemedia, Contacts)
; Return:     eax = HRESULT.
; Note:       To retrieve the perceived type use the AssocGetPerceivedType API.
;             dGlobal = TRUE requires adminitrative rights.

% include &ObjMemPath&Common\SetShellPerceivedType_TX.inc

end
