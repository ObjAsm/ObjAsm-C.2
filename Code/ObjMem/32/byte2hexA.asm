; ==================================================================================================
; Title:      byte2hexA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, July 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
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

.code
align ALIGN_CODE
byte2hexA proc pBuffer:POINTER, bValue:BYTE
  mov edx, [esp + 4]                                    ;edx -> Buffer
  mov cl, [esp + 8]                                     ;cl = bValue
  movzx eax, cl
  mov ax, DCHRA ptr HexCharTableA[sizeof(DCHRA)*eax]
  mov DCHRA ptr [edx], ax
  m2z CHRA ptr [edx + sizeof(DCHRA)]                    ;Set ZTC
  ret 8
byte2hexA endp

OPTION PROC:DEFAULT

end
