; ==================================================================================================
; Title:      DbgOutMem_UEFI.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemUefi.cop

ProcName textequ <DbgOutMem_UEFI>
BYTES_PER_LINE equ 8      ;Must be a multiple of 8

; --------------------------------------------------------------------------------------------------
; Procedure:  DbgOutMem_UEFI
; Purpose:    Output the content of a memory block.
; Arguments:  Arg1: -> Memory block.
;             Arg2: Memory block size.
;             Arg3: Representation format.
;             Arg4: Memory output RGB color value.
;             Arg5: Representation output RGB color value.
;             Arg6: Background RGB color value.
;             Arg7: -> Destination Window WIDE name.
; Return:     Nothing.

% include &ObjMemPath&Common\DbgOutMem_XP.inc

end
