; ==================================================================================================
; Title:      qword2hexW.asm
; Author:     G. Friedrich
; Version:    C.1.2
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.2 May 2020
;               - Bug correction.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

externdef HexCharTableW:CHRW

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  qword2hexW
; Purpose:    Convert a QWORD to its hexadecimal WIDE string representation.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: QWORD value.
; Return:     Nothing.
; Notes:      The destination buffer must be at least 34 BYTEs large to allocate the output string
;             (16 character WORDs + ZTC = 34 BYTEs).

OPTION PROC:NONE
align ALIGN_CODE
qword2hexW proc pBuffer:POINTER, qValue:QWORD
  ;rcx -> Buffer, edx = dValue
  mov r10, offset HexCharTableW

  ofs = 24
  repeat 4
    movzx eax, dl
    mov r8d, DCHRW ptr [r10 + sizeof(DCHRW)*rax]
    shr rdx, 8
    shl r8, 32
    movzx eax, dl
    mov r9d, DCHRW ptr [r10 + sizeof(DCHRW)*rax]
    shr rdx, 8
    or r8, r9
    mov [rcx + ofs], r8
    ofs = ofs - 8
  endm

  m2z CHRW ptr [rcx + 16*sizeof(CHRW)]                              ;Set ZTC
  ret
qword2hexW endp
OPTION PROC:DEFAULT

end
