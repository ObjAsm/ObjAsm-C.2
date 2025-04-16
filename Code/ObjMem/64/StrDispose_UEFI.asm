; ==================================================================================================
; Title:      StrDispose_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemUefi.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrDispose_UEFI
; Purpose:    Free the memory allocated for the string using StrNew_UEFI, StrCNew_UEFI, 
;             StrLENew_UEFI or StrAlloc_UEFI.
;             If the pointer to the string is NULL, StrDispose_UEFI does nothing.
; Arguments:  Arg1: -> String.
; Return:     Nothing.

% include &ObjMemPath&Common\StrDispose_TX_UEFI.inc

end
