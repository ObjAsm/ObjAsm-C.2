; ==================================================================================================
; Title:      Mem2HexW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

externdef HexCharTableW:WORD

; --------------------------------------------------------------------------------------------------
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
  mov edx, [esp + 4]                                    ;edx -> Buffer
  mov ecx, [esp + 8]                                    ;ecx -> Mem
  cmp DWORD ptr [esp + 12], 0
  .while !ZERO?
    movzx eax, BYTE ptr [ecx]
    mov eax, DWORD ptr [HexCharTableW + 4*eax]
    mov [edx], eax
    add edx, 4
    inc ecx
    dec DWORD ptr [esp + 12]
  .endw
  m2z WORD ptr [edx]                                    ;Set ZTC
  ret 12
Mem2HexW endp

OPTION PROC:DEFAULT

end
