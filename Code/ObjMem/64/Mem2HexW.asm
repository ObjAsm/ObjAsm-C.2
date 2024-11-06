; ==================================================================================================
; Title:      Mem2HexW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

externdef HexCharTableW:CHRW

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Mem2HexW
; Purpose:    Convert the memory content into a hex WIDE string representation.
; Arguments:  Arg1: -> WIDE character buffer.
;             Arg2: -> Source memory.
;             Arg3: Byte count.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
Mem2HexW proc pBuffer:POINTER, pMem:POINTER, dCount:DWORD
  ;rcx -> Buffer, rdx -> Mem, r8d = dCount
  mov r10, offset HexCharTableW
  .while r8d != 0
    movzx eax, BYTE ptr [rdx]
    mov eax, DCHRW ptr [r10 + sizeof(DCHRW)*rax]
    mov [rcx], eax
    add rcx, sizeof(DCHRW)
    inc rdx
    dec r8d
  .endw
  m2z CHRW ptr [rcx]                                    ;Set ZTC
  ret
Mem2HexW endp

OPTION PROC:DEFAULT

end
