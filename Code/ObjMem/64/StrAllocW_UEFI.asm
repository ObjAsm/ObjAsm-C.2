; ==================================================================================================
; Title:      StrAllocW_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemUefi.cop

ProcName textequ <StrAllocW_UEFI>

; --------------------------------------------------------------------------------------------------
; Procedure:  StrAllocW_UEFI
; Purpose:    Allocate space for a string with n characters.
; Arguments:  Arg1: Character count without the ZTC.
; Return:     rax -> New allocated string or NULL if failed.

% include &ObjMemPath&Common\StrAlloc_TX_UEFI.inc

end
