; ==================================================================================================
; Title:      Mem2HexA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

externdef HexCharTableA:CHRA

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Mem2HexA
; Purpose:    Convert the memory content into a hex ANSI string representation.
; Arguments:  Arg1: -> ANSI character buffer.
;             Arg2: -> Source memory.
;             Arg3: Byte count.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
Mem2HexA proc pBuffer:POINTER, pMem:POINTER, dCount:DWORD
  ;rcx -> Buffer, rdx -> Mem, r8d = dCount
  .while r8d != 0
    movzx eax, BYTE ptr [rdx]
    movzx eax, DCHRA ptr [HexCharTableA + sizeof(DCHRA)*rax]
    mov [rcx], ax
    add rcx, sizeof(DCHRA)
    inc rdx
    dec r8d
  .endw
  m2z CHRA ptr [rcx]                                    ;Set ZTC
  ret
Mem2HexA endp

OPTION PROC:DEFAULT

end
