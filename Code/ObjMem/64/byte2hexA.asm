; ==================================================================================================
; Title:      byte2hexA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, July 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

externdef HexCharTableA:CHRA

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  byte2hexA
; Purpose:    Convert a BYTE to its hexadecimal ANSI string representation.
; Arguments:  Arg1: -> Destination ANSI string buffer.
;             Arg2: BYTE value.
; Return:     Nothing.
; Notes:      The destination buffer must be at least 3 BYTEs large to allocate the output string
;             (2 character BYTEs + ZTC = 3 BYTEs).

OPTION PROC:NONE

align ALIGN_CODE
byte2hexA proc pBuffer:POINTER, bValue:BYTE
  ;rcx -> Buffer, dl = bValue
  mov r10, offset HexCharTableA
  movzx eax, dl
  mov r8w, DCHRA ptr [r10 + sizeof(DCHRA)*rax]
  mov [rcx], r8w
  m2z CHRA ptr [rcx + 2*sizeof(CHRA)]                   ;Set ZTC
  ret
byte2hexA endp
OPTION PROC:DEFAULT

end
