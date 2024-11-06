; ==================================================================================================
; Title:      MemAlloc_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemUefi.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemAlloc_UEFI
; Purpose:    Allocate a memory block.
; Arguments:  Arg1: Memory block attributes [0, MEM_INIT_ZERO].
;             Arg2: Memory block size in BYTEs.
; Return:     eax -> Memory block or NULL if failed.

% include &ObjMemPath&Common\MemAlloc_X_UEFI.inc

end
