; ==================================================================================================
; Title:      word2hexW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, July 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

externdef HexCharTableW:CHRW

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  word2hexW
; Purpose:    Convert a WORD to its hexadecimal WIDE string representation.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: WORD value.
; Return:     Nothing.
; Notes:      The destination buffer must be at least 9 BYTEs large to allocate the output string
;             (4 character WORDs + ZTC = 9 BYTEs).

OPTION PROC:NONE

align ALIGN_CODE
word2hexW proc pBuffer:POINTER, wValue:WORD
  ;rcx -> Buffer, dx = wValue
  mov r10, offset HexCharTableW
  movzx eax, dl
  mov r8d, DCHRW ptr [r10 + sizeof(DCHRW)*rax]
  shl r8, 32
  movzx eax, dh
  mov r9d, DCHRW ptr [r10 + sizeof(DCHRW)*rax]
  or r8, r9
  mov [rcx], r8
  m2z CHRW ptr [rcx + 4*sizeof(CHRW)]                   ;Set ZTC
  ret
word2hexW endp

OPTION PROC:DEFAULT

end
