; ==================================================================================================
; Title:      StrCNewW_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemUEFI.cop

ProcName textequ <StrCNewW_UEFI>

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCNewW_UEFI
; Purpose:    Allocate a new copy of the source WIDE string with length limitation.
;             If the pointer to the source string is NULL or points to an empty string, StrCNewW
;             returns NULL and doesn't allocate any heap space. Otherwise, StrCNewW makes a
;             duplicate of the source string. The maximal size of the new string is limited to the
;             second parameter.
; Arguments:  Arg1: -> Source WIDE string.
;             Arg2: Maximal character count.
; Return:     eax -> New WIDE string copy.

% include &ObjMemPath&Common\StrCNew_T32P.inc

end
