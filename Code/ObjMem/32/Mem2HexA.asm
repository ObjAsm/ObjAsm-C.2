; ==================================================================================================
; Title:      Mem2HexA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

externdef HexCharTableA:BYTE

; --------------------------------------------------------------------------------------------------
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
  mov edx, [esp + 4]                                    ;edx -> Buffer
  mov ecx, [esp + 8]                                    ;ecx -> Mem
  cmp DWORD ptr [esp + 12], 0
  .while !ZERO?
    movzx eax, BYTE ptr [ecx]
    movzx eax, WORD ptr [HexCharTableA + 2*eax]
    mov [edx], ax
    add edx, 2
    inc ecx
    dec DWORD ptr [esp + 12]
  .endw
  m2z BYTE ptr [edx]                                    ;Set ZTC
  ret 12
Mem2HexA endp

OPTION PROC:DEFAULT

end
