; ==================================================================================================
; Title:      DbgOutMem.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1 June 2022
;               - Bitness and Platform independent code.
;               - UEFI adaptation and addition of UI64, I64, H64.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <DbgOutMem>
BYTES_PER_LINE equ 16     ;Must be a multiple of 8

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutMem
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
