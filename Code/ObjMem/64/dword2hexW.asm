; ==================================================================================================
; Title:      dword2hexW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

externdef HexCharTableW:CHRW

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  dword2hexW
; Purpose:    Convert a DWORD to its hexadecimal WIDE string representation.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: DWORD value.
; Return:     Nothing.
; Notes:      The destination buffer must be at least 18 BYTEs large to allocate the output string
;             (8 character WORDs + ZTC = 18 BYTEs).

OPTION PROC:NONE
align ALIGN_CODE
dword2hexW proc pBuffer:POINTER, dValue:DWORD
  ;rcx -> Buffer, edx = dValue
  mov r10, offset HexCharTableW
  movzx eax, dl
  mov r8d, DCHRW ptr [r10 + sizeof(DCHRW)*rax]
  shr edx, 8
  shl r8, 32
  movzx eax, dl
  mov r9d, DCHRW ptr [r10 + sizeof(DCHRW)*rax]
  shr edx, 8
  or r8, r9
  mov [rcx + 2*sizeof(DCHRW)], r8

  movzx eax, dl
  mov r8d, DCHRW ptr [r10 + sizeof(DCHRW)*rax]
  shr edx, 8
  shl r8, 32
  movzx eax, dl
  mov r9d, DCHRW ptr [r10 + sizeof(DCHRW)*rax]
  or r8, r9
  mov [rcx], r8

  m2z CHRW ptr [rcx + 8*sizeof(CHRW)]                   ;Set ZTC
  ret
dword2hexW endp
OPTION PROC:DEFAULT

end
