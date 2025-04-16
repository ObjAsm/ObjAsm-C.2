; ==================================================================================================
; Title:      byte2hexW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, July 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

externdef HexCharTableW:CHRW

; --------------------------------------------------------------------------------------------------
; Procedure:  byte2hexW
; Purpose:    Convert a BYTE to its hexadecimal WIDE string representation.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: BYTE value.
; Return:     Nothing.
; Notes:      The destination buffer must be at least 5 BYTEs large to allocate the output string
;             (2 character WORDs + ZTC = 5 BYTEs).

OPTION PROC:NONE

align ALIGN_CODE
byte2hexW proc pBuffer:POINTER, bValue:BYTE
  ;rcx -> Buffer, dl = bValue
  mov r10, offset HexCharTableW
  movzx eax, dl
  mov r8d, DCHRW ptr [r10 + sizeof(DCHRW)*rax]
  mov [rcx], r8d
  m2z CHRW ptr [rcx + 2*sizeof(CHRW)]                   ;Set ZTC
  ret
byte2hexW endp
OPTION PROC:DEFAULT

end
