; ==================================================================================================
; Title:      byte2hexW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, July 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

externdef HexCharTableW:CHRW

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  byte2hexW
; Purpose:    Convert a BYTE to its hexadecimal WIDE string representation.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: BYTE value.
; Return:     Nothing.
; Notes:      The destination buffer must be at least 5 BYTEs large to allocate the output string
;             (2 character WORDs + ZTC = 5 BYTEs).

OPTION PROC:NONE

.code
align ALIGN_CODE
byte2hexW proc pBuffer:POINTER, bValue:BYTE
  mov edx, [esp + 4]                                    ;edx -> Buffer
  mov cl, [esp + 8]                                     ;cl = bValue
  movzx eax, cl
  mov eax, DCHRW ptr HexCharTableW[sizeof(DCHRW)*eax]
  mov DCHRW ptr [edx], eax
  m2z CHRW ptr [edx + sizeof(DCHRW)]                    ;Set ZTC
  ret 8
byte2hexW endp

OPTION PROC:DEFAULT

end
