; ==================================================================================================
; Title:      qword2hexA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

externdef HexCharTableA:CHRA

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  qword2hexA
; Purpose:    Convert a QWORD to its hexadecimal ANSI string representation.
; Arguments:  Arg1: -> Destination ANSI string buffer.
;             Arg2: QWORD value.
; Return:     Nothing.
; Note:       The destination buffer must be at least 17 BYTEs large to allocate the output string
;             (16 character BYTEs + ZTC = 17 BYTEs).

OPTION PROC:NONE
align ALIGN_CODE
qword2hexA proc pBuffer:POINTER, qValue:QWORD
  ;rcx -> Buffer, rdx = qValue
  mov r10, offset HexCharTableA
  movzx eax, dl
  mov r8w, DCHRA ptr [r10 + sizeof(DCHRA)*rax]
  shr rdx, 8
  shl r8, 16
  movzx eax, dl
  mov r8w, DCHRA ptr [r10 + sizeof(DCHRA)*rax]
  shr rdx, 8
  shl r8, 16
  movzx eax, dl
  mov r8w, DCHRA ptr [r10 + sizeof(DCHRA)*rax]
  shr rdx, 8
  shl r8, 16
  movzx eax, dl
  mov r8w, DCHRA ptr [r10 + sizeof(DCHRA)*rax]
  mov [rcx + 8], r8

  shr rdx, 8
  movzx eax, dl
  mov r8w, DCHRA ptr [r10 + sizeof(DCHRA)*rax]
  shr rdx, 8
  shl r8, 16
  movzx eax, dl
  mov r8w, DCHRA ptr [r10 + sizeof(DCHRA)*rax]
  shr rdx, 8
  shl r8, 16
  movzx eax, dl
  mov r8w, DCHRA ptr [r10 + sizeof(DCHRA)*rax]
  shr rdx, 8
  shl r8, 16
  movzx eax, dl
  mov r8w, DCHRA ptr [r10 + sizeof(DCHRA)*rax]
  mov [rcx], r8

  m2z CHRA ptr [rcx + 16*sizeof(CHRA)]                              ;Set ZTC
  ret
qword2hexA endp
OPTION PROC:DEFAULT

end
